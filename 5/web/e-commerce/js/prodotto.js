document.addEventListener('DOMContentLoaded', function () {
    // Ottieni l'ID del prodotto dalla URL
    const urlParams = new URLSearchParams(window.location.search);
    const prodottoId = parseInt(urlParams.get('id'));

    // Carica i prodotti dal file JSON
    fetch('json/prodotti.json')
        .then(response => response.json())
        .then(prodotti => {
            // Trova il prodotto con l'ID corrispondente
            const prodotto = prodotti.find(p => p.id === prodottoId);

            if (prodotto) {
                const prodottoContainer = document.getElementById('prodotto-container');
                
                // Creiamo gli elementi in modo dinamico e li aggiungiamo al DOM

                // Contenitore principale (row)
                const rowDiv = document.createElement('div');
                rowDiv.classList.add('row');

                // Colonna per l'immagine
                const colImgDiv = document.createElement('div');
                colImgDiv.classList.add('col-md-6');
                const img = document.createElement('img');
                img.src = prodotto.immagine;
                img.classList.add('img-fluid');
                img.alt = prodotto.descrizione_img;
                colImgDiv.appendChild(img);

                // Colonna per il nome, prezzo e bottone
                const colInfoDiv = document.createElement('div');
                colInfoDiv.classList.add('col-md-6');
                const nomeProdotto = document.createElement('h2');
                nomeProdotto.textContent = prodotto.nome;
                const prezzoProdotto = document.createElement('p');
                prezzoProdotto.innerHTML = `<strong>Prezzo:</strong> ${prodotto.prezzo}`;
                
                // Se il prodotto ha delle misure disponibili, aggiungi un selettore
                if (prodotto.misure_disponibili && prodotto.misure_disponibili.length > 0) {
                    const selettoreMisura = document.createElement('select');
                    selettoreMisura.classList.add('form-select');
                    selettoreMisura.id = 'misura-select';

                    prodotto.misure_disponibili.forEach(misura => {
                        const option = document.createElement('option');
                        option.value = misura.misura;
                        option.textContent = `${misura.misura} - ${misura.prezzo}`;
                        selettoreMisura.appendChild(option);
                    });

                    colInfoDiv.appendChild(selettoreMisura);
                }

                const addButton = document.createElement('button');
                addButton.classList.add('btn', 'btn-primary');
                addButton.textContent = 'Aggiungi al carrello';

                // Aggiungiamo l'evento di click al bottone per aggiungere al carrello
                addButton.addEventListener('click', () => {
                    const misuraSelezionata = document.getElementById('misura-select') ? document.getElementById('misura-select').value : null;
                    const prodottoConMisura = misuraSelezionata ? {...prodotto, misura: misuraSelezionata} : prodotto;
                    aggiungiAlCarrello(prodottoConMisura);
                });

                // Aggiungiamo nome, prezzo e bottone alla colonna
                colInfoDiv.appendChild(nomeProdotto);
                colInfoDiv.appendChild(prezzoProdotto);
                colInfoDiv.appendChild(addButton);

                // Aggiungiamo le due colonne alla riga
                rowDiv.appendChild(colImgDiv);
                rowDiv.appendChild(colInfoDiv);

                // Aggiungiamo la riga al contenitore
                prodottoContainer.appendChild(rowDiv);

                // Descrizione del prodotto sotto la riga
                const rowDescrizioneDiv = document.createElement('div');
                rowDescrizioneDiv.classList.add('row', 'mt-4');
                const colDescrizioneDiv = document.createElement('div');
                colDescrizioneDiv.classList.add('col-md-12');
                const descrizioneHeader = document.createElement('h3');
                descrizioneHeader.textContent = 'Descrizione';
                const descrizioneP = document.createElement('p');
                descrizioneP.textContent = prodotto.descrizione;

                // Aggiungiamo la descrizione alla colonna
                colDescrizioneDiv.appendChild(descrizioneHeader);
                colDescrizioneDiv.appendChild(descrizioneP);

                // Aggiungiamo la colonna di descrizione alla riga
                rowDescrizioneDiv.appendChild(colDescrizioneDiv);

                // Aggiungiamo la riga di descrizione al contenitore
                prodottoContainer.appendChild(rowDescrizioneDiv);
            } else {
                // Se il prodotto non viene trovato
                document.getElementById('prodotto-container').innerHTML = '<p>Prodotto non trovato.</p>';
            }
        })
        .catch(err => console.error("Errore nel caricamento del prodotto:", err));
});
