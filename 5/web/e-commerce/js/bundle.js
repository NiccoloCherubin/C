document.addEventListener('DOMContentLoaded', function () {
    // Recupera i bundle dal file JSON
    fetch('json/bundle.json')
        .then(response => response.json())  // Converte la risposta in formato JSON
        .then(bundles => {
            const container = document.getElementById('bundle-container');

            // Crea un contenitore con la classe "row" per la griglia di Bootstrap
            const rowDiv = document.createElement('div');
            rowDiv.classList.add('row', 'g-4');

            // Per ogni bundle, crea dinamicamente gli elementi HTML
            bundles.forEach(bundle => {
                const bundleDiv = document.createElement('div');
                bundleDiv.classList.add('col-12', 'col-md-4');

                // Crea la card per ogni bundle
                const cardDiv = document.createElement('div');
                cardDiv.classList.add('card', 'h-100');

                // Crea il link per il bundle
                const linkBundle = document.createElement('a');
                linkBundle.href = `bundle.html?id=${bundle.id}`;

                // Crea l'immagine
                const img = document.createElement('img');
                img.src = bundle.immagine;
                img.alt = bundle.descrizione_img;
                img.classList.add('card-img-top', 'bundle-img');

                // Aggiungi immagine al link
                linkBundle.appendChild(img);

                // Crea il corpo della card
                const cardBody = document.createElement('div');
                cardBody.classList.add('card-body');

                // Crea il nome del bundle
                const nomeBundle = document.createElement('h5');
                nomeBundle.textContent = bundle.nome;
                nomeBundle.classList.add('card-title');

                // Crea il prezzo del bundle
                const prezzoBundle = document.createElement('h6');
                prezzoBundle.textContent = bundle.prezzo;
                prezzoBundle.classList.add('card-subtitle', 'mb-2', 'text-muted');

                // Crea il tasto per aggiungere il bundle al carrello
                const addButton = document.createElement('button');
                addButton.classList.add('btn', 'btn-primary');
                addButton.textContent = 'Aggiungi al carrello';

                // Aggiungi il click handler per il tasto
                addButton.addEventListener('click', () => {
                    // Aggiungi i prodotti del bundle come un solo prodotto al carrello
                    aggiungiAlCarrello(bundle);
                });

                cardBody.appendChild(nomeBundle);
                cardBody.appendChild(prezzoBundle);
                cardBody.appendChild(addButton);

                // Aggiungi immagine e corpo della card al div della card
                cardDiv.appendChild(linkBundle);
                cardDiv.appendChild(cardBody);

                // Aggiungi il bundle alla riga
                bundleDiv.appendChild(cardDiv);
                rowDiv.appendChild(bundleDiv);
            });

            // Aggiungi la riga al contenitore
            container.appendChild(rowDiv);
        })
        .catch(error => {
            console.error("Errore nel caricamento dei bundle: ", error);
        });
});

// Funzione per aggiungere il prodotto (bundle) al carrello
function aggiungiAlCarrello(bundle) {
    let carrello = JSON.parse(localStorage.getItem('carrello')) || [];

    // Controlla se il bundle è già nel carrello
    let prodottoEsistente = carrello.find(p => p.id === bundle.id);

    if (prodottoEsistente) {
        prodottoEsistente.quantita++;
    } else {
        let nuovoBundle = {
            id: bundle.id,
            nome: bundle.nome,
            prezzo: bundle.prezzo,
            immagine: bundle.immagine,
            descrizione_img: bundle.descrizione_img,
            prodotti: bundle.prodotti,  // Mantiene la lista prodotti
            quantita: 1
        };

        carrello.push(nuovoBundle);
    }

    localStorage.setItem('carrello', JSON.stringify(carrello));

    alert(`${bundle.nome} è stato aggiunto al carrello!`);
}


    // Verifica se il bundle è già nel carrello
    const prodottoEsistente = carrello.find(p => p.id === prodottoBundle.id);

    if (prodottoEsistente) {
        // Se il prodotto è già nel carrello ne incrementa la quantità
        prodottoEsistente.quantita++;
    } else {
        //  aggiunge il prodotto al carrello con una quantità di 1
        carrello.push(prodottoBundle);
    }

    // Salva il carrello nel localStorage
    localStorage.setItem('carrello', JSON.stringify(carrello));

    // Notifica l'utente che il bundle è stato aggiunto
    alert(`${prodottoBundle.nome} è stato aggiunto al carrello!`);
