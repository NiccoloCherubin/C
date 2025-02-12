document.addEventListener('DOMContentLoaded', function() {
    let carrello = JSON.parse(localStorage.getItem('carrello')) || [];
    const carrelloContainer = document.getElementById('carrello-container');
    const totaleCarrelloElem = document.getElementById('totale-carrello');
    const scontoApp = document.getElementById('sconto-applicato');

    // Funzione per calcolare il totale del carrello
    function calcolaTotale() {
    let totale = 0;
    carrello.forEach(prodotto => {
        // Rimuovi il simbolo dell'euro e converte in numero
        const prezzo = parseFloat(prodotto.prezzo.replace('€', '').trim()); // Rimuovi simbolo e spazio
        const quantita = parseInt(prodotto.quantita, 10); // Assicurati che sia un intero
        if (!isNaN(prezzo) && !isNaN(quantita)) {
            totale += prezzo * quantita;
        }
    });
    totaleCarrelloElem.textContent = totale.toFixed(2);
}


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
        carrello = carrello.filter(p => p.id !== id);
        localStorage.setItem('carrello', JSON.stringify(carrello));
        location.reload();
    };

    // Funzione per svuotare il carrello
    window.svuotaCarrello = function() {
        localStorage.removeItem('carrello');
        location.reload();
    };

    // Funzione per applicare il codice sconto
    window.applicaCodiceSconto = function() {
        const codiceSconto = document.getElementById('codice-sconto').value.trim().toUpperCase();
        let sconto = 0;
    
        // Codici sconto predefiniti (puoi modificarli)
        if (codiceSconto === "A") {
            sconto = 0.10; // 10% di sconto
        } else if (codiceSconto === "B") {
            sconto = 0.20; // 20% di sconto
        } else {
            // Codice sconto non valido
            scontoApp.textContent = "Codice sconto non valido!";
            return;
        }
    
        // Calcola il totale
        const totale = parseFloat(totaleCarrelloElem.textContent); // Ottieni il totale corrente
        const totaleScontato = totale * (1 - sconto); // Applica lo sconto
    
        // Mostra il nuovo totale scontato
        totaleCarrelloElem.textContent = totaleScontato.toFixed(2);
    
        // Mostra il messaggio di sconto applicato
        scontoApp.textContent = `Sconto applicato: ${Math.round(sconto * 100)}%`;
    
        // Rimuovi il codice sconto dalla barra di input
        document.getElementById('codice-sconto').value = '';
    };
    

    // Calcola il totale iniziale
    calcolaTotale();
});
