fetch('json/prodotti.json')
  .then(response => response.json())
  .then(prodotti => {
    const container = document.getElementById('prodotti-container');

    // Limita ai primi due prodotti
    const primiDueProdotti = prodotti.slice(0, 2);

    // Per ogni prodotto, crea dinamicamente gli elementi HTML
    primiDueProdotti.forEach(prodotto => {
      const prodottoDiv = document.createElement('div');
      prodottoDiv.classList.add('col-md-6', 'mb-4');

      // Crea la card per ogni prodotto
      const cardDiv = document.createElement('div');
      cardDiv.classList.add('card', 'h-100');

      // Crea l'immagine
      const img = document.createElement('img');
      img.src = prodotto.immagine;
      img.alt = prodotto.descrizione_img;
      img.classList.add('card-img-top');

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

      // Crea il bottone per aggiungere al carrello
      const addButton = document.createElement('button');
      addButton.classList.add('btn', 'btn-primary');
      addButton.textContent = 'Aggiungi al carrello';
      addButton.onclick = () => aggiungiAlCarrello(prodotto);  //evento per il carrello

      // Aggiunge gli elementi alla card
      cardBody.appendChild(nomeProdotto);
      cardBody.appendChild(prezzoProdotto);
      cardBody.appendChild(addButton);

      // Aggiunge immagine e corpo della card al div della card
      cardDiv.appendChild(img);
      cardDiv.appendChild(cardBody);

      // Aggiunge la card al div del prodotto
      prodottoDiv.appendChild(cardDiv);

      // Aggiunge il prodotto al contenitore principale
      container.appendChild(prodottoDiv);
    });
  })
  .catch(error => {
    console.error("Errore nel caricamento dei prodotti: ", error);
  });