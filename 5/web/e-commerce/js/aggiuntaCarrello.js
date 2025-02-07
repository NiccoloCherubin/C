/**
 * Aggiunge un prodotto al carrello nel localStorage
 * @param {Object} prodotto Il prodotto da aggiungere
 */
function aggiungiAlCarrello(prodotto) {
    // Recupera il carrello dal localStorage o crea un nuovo carrello vuoto
    let carrello = JSON.parse(localStorage.getItem('carrello')) || [];

    // Controlla se il prodotto è già nel carrello
    const prodottoEsistente = carrello.find(p => p.id === prodotto.id);
    
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