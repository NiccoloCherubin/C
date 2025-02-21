function aggiungiAlCarrello(prodotto) {
    // Recupera il carrello dal localStorage o crea un nuovo carrello vuoto
    let carrello = JSON.parse(localStorage.getItem('carrello')) || [];

    // Se il prodotto ha una misura selezionata, aggiungila al nome o al campo del prodotto
    if (prodotto.misura) {
        prodotto.nome = `${prodotto.nome} - ${prodotto.misura}`;
    }

    // Controlla se il prodotto è già nel carrello
    const prodottoEsistente = carrello.find(p => p.id === prodotto.id && p.misura === prodotto.misura);
    
    if (prodottoEsistente) {
        // Se il prodotto è già nel carrello, incrementa la quantità
        prodottoEsistente.quantita++;
    } else {
        // Altrimenti, aggiungi il prodotto al carrello con una quantità di 1
        prodotto.quantita = 1;
        carrello.push(prodotto);
    }

    // Salva il carrello nel localStorage
    localStorage.setItem('carrello', JSON.stringify(carrello));

    // Opzionale: notifica all'utente che il prodotto è stato aggiunto
    alert(`${prodotto.nome} è stato aggiunto al carrello!`);
}
