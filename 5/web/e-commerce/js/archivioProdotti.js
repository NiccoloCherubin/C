// Recupera i dati dal file JSON
fetch('json/prodotti.json')
  .then(response => response.json()) // Converte la risposta in formato JSON
  .then(prodotti => {
    const container = document.getElementById('prodotti-container');

    // Per ogni prodotto, crea dinamicamente gli elementi HTML
    prodotti.forEach(prodotto => {
      const prodottoDiv = document.createElement('div');
      prodottoDiv.classList.add('prodotto-item');
      
      // Crea l'immagine
      const img = document.createElement('img');
      img.src = prodotto.immagine;
      img.alt = prodotto.descrizione_img;
      img.classList.add('prodotto-img');
      
      // Crea il prezzo del prodotto (h3)
      const prezzoProdotto = document.createElement('h3');
      prezzoProdotto.textContent = prodotto.prezzo;
      prezzoProdotto.classList.add('prodotto-prezzo');
      
      // Aggiungi gli elementi (immagine e prezzo) al div del prodotto
      prodottoDiv.appendChild(img);
      prodottoDiv.appendChild(prezzoProdotto);
      
      // Aggiungi il prodotto al contenitore
      container.appendChild(prodottoDiv);
    });
  })
  .catch(error => {
    console.error("Errore nel caricamento dei prodotti: ", error);
  });
