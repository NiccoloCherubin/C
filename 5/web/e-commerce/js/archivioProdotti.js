document.addEventListener('DOMContentLoaded', function () {
    // Recupera i prodotti dal file JSON
    fetch('json/prodotti.json')
        .then(response => response.json())  // Converte la risposta in formato JSON
        .then(prodotti => {
            const container = document.getElementById('prodotti-container');

            // Creiamo un contenitore con la classe "row" per la griglia di Bootstrap
            const rowDiv = document.createElement('div');
            rowDiv.classList.add('row', 'g-4');  // Classe "row" per griglia e "g-4" per gap tra colonne

            // Per ogni prodotto, crea dinamicamente gli elementi HTML
            prodotti.forEach(prodotto => {
                const prodottoDiv = document.createElement('div');
                prodottoDiv.classList.add('col-12', 'col-md-4');  // 1 colonna su mobile, 4 su dispositivi medi (tablet, desktop)

                // Crea la card per ogni prodotto
                const cardDiv = document.createElement('div');
                cardDiv.classList.add('card', 'h-100');

                // Crea il link per il prodotto
                const linkProdotto = document.createElement('a');
                linkProdotto.href = `prodotto.html?id=${prodotto.id}`;  // Aggiungi il link al prodotto

                // Crea l'immagine
                const img = document.createElement('img');
                img.src = prodotto.immagine;
                img.alt = prodotto.descrizione_img;
                img.classList.add('card-img-top', 'prodotto-img');

                // Aggiungi immagine al link
                linkProdotto.appendChild(img);

                // Crea il corpo della card
                const cardBody = document.createElement('div');
                cardBody.classList.add('card-body');

                // Crea il nome del prodotto
                const nomeProdotto = document.createElement('h5');
                nomeProdotto.textContent = prodotto.nome;
                nomeProdotto.classList.add('card-title');

                // Crea il prezzo del prodotto
                const prezzoProdotto = document.createElement('h6');
                prezzoProdotto.textContent = prodotto.prezzo;
                prezzoProdotto.classList.add('card-subtitle', 'mb-2', 'text-muted');

                // Verifica se il prodotto ha opzioni (misure) disponibili
                if (prodotto.misure_disponibili && prodotto.misure_disponibili.length > 0) {
                    // Se ha misure, non mostriamo il tasto "Aggiungi al carrello", ma aggiungiamo automaticamente la prima misura
                    const addButton = document.createElement('button');
                    addButton.classList.add('btn', 'btn-primary');
                    addButton.textContent = 'Aggiungi al carrello';

                    // Aggiungi automaticamente la prima misura al carrello
                    addButton.addEventListener('click', () => {
                        const primaMisura = prodotto.misure_disponibili[0];  // Seleziona la prima misura
                        prodotto.misura = primaMisura.misura;  // Aggiungi la misura al prodotto
                        prodotto.prezzo = primaMisura.prezzo;  // Imposta il prezzo della misura
                        aggiungiAlCarrello(prodotto);  // Aggiungi il prodotto al carrello
                    });

                    cardBody.appendChild(nomeProdotto);
                    cardBody.appendChild(prezzoProdotto);
                    cardBody.appendChild(addButton);
                } else {
                    // Se non ci sono misure, mostriamo comunque il bottone per aggiungere al carrello
                    const addButton = document.createElement('button');
                    addButton.classList.add('btn', 'btn-primary');
                    addButton.textContent = 'Aggiungi al carrello';
                    addButton.addEventListener('click', () => aggiungiAlCarrello(prodotto));

                    cardBody.appendChild(nomeProdotto);
                    cardBody.appendChild(prezzoProdotto);
                    cardBody.appendChild(addButton);
                }

                // Aggiungi immagine e corpo della card al div della card
                cardDiv.appendChild(linkProdotto);
                cardDiv.appendChild(cardBody);

                // Aggiungi la card al div del prodotto
                prodottoDiv.appendChild(cardDiv);

                // Aggiungi il prodotto alla riga
                rowDiv.appendChild(prodottoDiv);
            });

            // Aggiungi la riga al contenitore
            container.appendChild(rowDiv);
        })
        .catch(error => {
            console.error("Errore nel caricamento dei prodotti: ", error);
        });
});

// Funzione per aggiungere il prodotto al carrello
function aggiungiAlCarrello(prodotto) {
    // Logica per aggiungere il prodotto al carrello 
    console.log(`Prodotto aggiunto al carrello: ${prodotto.nome}`);
}
