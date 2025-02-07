document.addEventListener('DOMContentLoaded', function () {
    // Ottieni l'ID del prodotto dalla URL
    const urlParams = new URLSearchParams(window.location.search);
    const prodottoId = parseInt(urlParams.get('id'));

    // Carica i prodotti dal file JSON
    fetch('prodotti.json')
        .then(response => response.json())
        .then(prodotti => {
            // Trova il prodotto con l'ID corrispondente
            const prodotto = prodotti.find(p => p.id === prodottoId);

            if (prodotto) {
                const prodottoContainer = document.getElementById('prodotto-container');
                
                // Mostra i dettagli del prodotto
                prodottoContainer.innerHTML = `
                    <div class="row">
                        <div class="col-md-6">
                            <img src="${prodotto.immagine}" class="img-fluid" alt="${prodotto.descrizione_img}">
                        </div>
                        <div class="col-md-6">
                            <h2>${prodotto.nome}</h2>
                            <p>${prodotto.prezzo}</p>
                            <p><strong>Descrizione:</strong> ${prodotto.descrizione_img}</p>
                            <button class="btn btn-primary">Aggiungi al carrello</button>
                        </div>
                    </div>
                `;
            } else {
                // Se il prodotto non viene trovato
                document.getElementById('prodotto-container').innerHTML = '<p>Prodotto non trovato.</p>';
            }
        })
        .catch(err => console.error("Errore nel caricamento del prodotto:", err));
});
