// Funzione per caricare i contenuti dal file JSON
async function loadSocketContent() {
    try {
        // Carica il file JSON
        const response = await fetch('json/socketContent.json');
        
        // Verifica che la risposta sia ok
        if (!response.ok) {
            throw new Error('Errore nel caricamento del file JSON');
        }

        // Converte la risposta in formato JSON
        const data = await response.json();

        // Imposta il titolo della pagina
        document.getElementById('page-title').textContent = data.title;

        // Crea le card con i dettagli sui socket
        const cardContainer = document.getElementById('card-container');
        data.cards.forEach(card => {
            const cardElement = document.createElement('div');
            cardElement.classList.add('col-md-6');
            cardElement.innerHTML = `
                <div class="card mb-4">
                    <div class="card-header bg-primary text-white">
                        ${card.header}
                    </div>
                    <div class="card-body">
                        <p class="card-text">${card.body}</p>
                    </div>
                </div>
            `;
            cardContainer.appendChild(cardElement);
        });

        // Crea gli accordion con i dettagli
        const accordionContainer = document.getElementById('accordionSocket');
        data.accordion.forEach((item, index) => {
            const accordionItem = document.createElement('div');
            accordionItem.classList.add('accordion-item');
            accordionItem.innerHTML = `
                <h2 class="accordion-header" id="heading${index}">
                    <button class="accordion-button" type="button" data-bs-toggle="collapse" data-bs-target="#collapse${index}" aria-expanded="${index === 0 ? 'true' : 'false'}" aria-controls="collapse${index}">
                        ${item.header}
                    </button>
                </h2>
                <div id="collapse${index}" class="accordion-collapse collapse ${index === 0 ? 'show' : ''}" aria-labelledby="heading${index}" data-bs-parent="#accordionSocket">
                    <div class="accordion-body">
                        ${item.body}
                    </div>
                </div>
            `;
            accordionContainer.appendChild(accordionItem);
        });

    } catch (error) {
        console.error("Errore nel caricamento dei contenuti:", error);
    }
}

// Carica i contenuti quando la pagina è pronta
window.onload = loadSocketContent;
