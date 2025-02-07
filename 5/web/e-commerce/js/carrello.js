document.addEventListener('DOMContentLoaded', function() {
    // Recupera il carrello da localStorage
    let carrello = JSON.parse(localStorage.getItem('carrello')) || [];
    const carrelloContainer = document.getElementById('carrello-container');

    // Se il carrello è vuoto
    if (carrello.length === 0) {
        carrelloContainer.innerHTML = '<p>Il tuo carrello è vuoto!</p>';
    } else {
        // Cicla attraverso i prodotti nel carrello
        carrello.forEach(prodotto => {
            const prodottoDiv = document.createElement('div');
            prodottoDiv.classList.add('d-flex', 'justify-content-between', 'align-items-center', 'mb-3');

            prodottoDiv.innerHTML = `
                <div>
                    <h5>${prodotto.nome}</h5>
                    <p>${prodotto.prezzo} x ${prodotto.quantita}</p>
                </div>
                <div>
                    <button class="btn btn-danger" onclick="rimuoviDalCarrello(${prodotto.id})">Rimuovi</button>
                </div>
            `;

            carrelloContainer.appendChild(prodottoDiv);
        });
    }

    // Funzione per rimuovere un prodotto dal carrello
    window.rimuoviDalCarrello = function(id) {
        // Filtra il carrello per rimuovere il prodotto con l'id corrispondente
        carrello = carrello.filter(p => p.id !== id);
        // Salva nuovamente il carrello aggiornato nel localStorage
        localStorage.setItem('carrello', JSON.stringify(carrello));
        // Ricarica la pagina per riflettere il cambiamento
        location.reload();
    };

    // Funzione per svuotare il carrello
    window.svuotaCarrello = function() {
        // Rimuovi il carrello dal localStorage
        localStorage.removeItem('carrello');
        // Ricarica la pagina per aggiornare lo stato
        location.reload();
    };
});
