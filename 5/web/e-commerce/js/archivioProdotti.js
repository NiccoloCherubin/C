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
      
      // Crea la descrizione dell'immagine (h3)
      const descrizioneImg = document.createElement('h3');
      descrizioneImg.textContent = prodotto.descrizione_img;
      descrizioneImg.classList.add('img-desc');
      
      // Crea la descrizione del prodotto (p)
      const descrizioneProdotto = document.createElement('p');
      descrizioneProdotto.textContent = prodotto.descrizione;
      descrizioneProdotto.classList.add('prodotto-desc');
      
      // Aggiungi gli elementi (immagine, descrizione immagine, descrizione prodotto) al div del prodotto
      prodottoDiv.appendChild(img);
      prodottoDiv.appendChild(descrizioneImg);
      prodottoDiv.appendChild(descrizioneProdotto);
      
      // Aggiungi il prodotto alla pagina
      container.appendChild(prodottoDiv);
    });
  })
  .catch(error => {
    console.error("Errore nel caricamento dei prodotti: ", error);
  });
