document.addEventListener('DOMContentLoaded', function() {
    let carrello = JSON.parse(localStorage.getItem('carrello')) || [];
    const carrelloContainer = document.getElementById('carrello-container');
    const totaleCarrelloElem = document.getElementById('totale-carrello');
    const scontoApp = document.getElementById('sconto-applicato');
    const btnSconto = document.querySelector('button[onclick="applicaCodiceSconto()"]');

    let scontoApplicato = false;

    function calcolaTotale() {
        let totale = 0;
        carrello.forEach(prodotto => {
            let prezzoPulito = parseFloat(prodotto.prezzo.replace('€', '').trim());
            totale += prezzoPulito * parseInt(prodotto.quantita, 10);
        });
        totaleCarrelloElem.textContent = totale.toFixed(2);
    }
    

    if (carrello.length === 0) {
        carrelloContainer.innerHTML = '<p>Il tuo carrello è vuoto!</p>';
    } else {
        carrello.forEach(prodotto => {
            const prodottoDiv = document.createElement('div');
            prodottoDiv.classList.add('d-flex', 'justify-content-between', 'align-items-center', 'mb-3');

            prodottoDiv.innerHTML = `
                <div class="d-flex align-items-center">
                    <img src="${prodotto.immagine.startsWith('http') ? prodotto.immagine : 'img/' + prodotto.immagine}" 
                         alt="${prodotto.nome}" class="img-fluid me-3" style="width: 60px; height: 60px; object-fit: cover;">
                    <div>
                        <h5>${prodotto.nome}</h5>
                        <p>${prodotto.prezzo} € x ${prodotto.quantita}</p>
                    </div>
                </div>
                <button class="btn btn-danger" onclick="rimuoviDalCarrello(${prodotto.id})">Rimuovi</button>
            `;

            carrelloContainer.appendChild(prodottoDiv);
        });
    }

    window.rimuoviDalCarrello = function(id) {
        carrello = carrello.filter(p => p.id !== id);
        localStorage.setItem('carrello', JSON.stringify(carrello));
        location.reload();
    };

    window.svuotaCarrello = function() {
        localStorage.removeItem('carrello');
        location.reload();
    };

    window.applicaCodiceSconto = function() {
        if (scontoApplicato) return;

        const codice = document.getElementById('codice-sconto').value.trim().toUpperCase();
        const sconto = codice === "A" ? 0.10 : codice === "B" ? 0.20 : 0;
        if (!sconto) return scontoApp.textContent = "Codice non valido!";

        totaleCarrelloElem.textContent = (parseFloat(totaleCarrelloElem.textContent) * (1 - sconto)).toFixed(2);
        scontoApp.textContent = `Sconto applicato: ${Math.round(sconto * 100)}%`;
        btnSconto.disabled = true;
        scontoApplicato = true;
    };

    calcolaTotale();
});
