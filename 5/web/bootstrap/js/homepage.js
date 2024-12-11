// Funzione per caricare il contenuto della homepage dal file JSON
async function loadHomePageContent() {
    try {
        // Effettua una richiesta al file JSON
        const response = await fetch("json/homePageContent.json");

        // Verifica che la risposta sia ok
        if (!response.ok) {
            throw new Error("Errore nel caricamento del file JSON");
        }

        // Converte la risposta in formato JSON
        const data = await response.json();

        // 1. Imposta il titolo della pagina
        document.getElementById("page-title").textContent = data.alert.title;

        // 2. Imposta l'alert
        const alertContainer = document.getElementById("alert-container");
        alertContainer.innerHTML = `<strong>${data.alert.title}</strong> ${data.alert.message}`;

        // 3. Crea le cards
        const cardsContainer = document.getElementById("cards-container");
        data.cards.forEach(card => {
            const cardElement = document.createElement("div");
            cardElement.classList.add("col-md-4");
            cardElement.innerHTML = `
                <div class="card">
                    <div class="card-body">
                        <h5 class="card-title">${card.title}</h5>
                        <p class="card-text">${card.description}</p>
                        <a href="${card.link}" class="btn btn-primary">${card.buttonText}</a>
                    </div>
                </div>
            `;
            cardsContainer.appendChild(cardElement);
        });

        // 4. Crea l'accordion
        const accordionContainer = document.getElementById("accordionExample");
        data.accordion.forEach((item, index) => {
            const accordionItem = document.createElement("div");
            accordionItem.classList.add("accordion-item");
            accordionItem.innerHTML = `
                <h2 class="accordion-header" id="heading${index}">
                    <button class="accordion-button ${index !== 0 ? 'collapsed' : ''}" type="button" data-bs-toggle="collapse" data-bs-target="#collapse${index}" aria-expanded="${index === 0 ? 'true' : 'false'}" aria-controls="collapse${index}">
                        ${item.heading}
                    </button>
                </h2>
                <div id="collapse${index}" class="accordion-collapse collapse ${index === 0 ? 'show' : ''}" aria-labelledby="heading${index}" data-bs-parent="#accordionExample">
                    <div class="accordion-body">
                        ${item.body}
                    </div>
                </div>
            `;
            accordionContainer.appendChild(accordionItem);
        });
    } catch (error) {
        console.error("Errore nel caricamento della homepage:", error);
    }
}

// Carica i contenuti quando la pagina è pronta
window.onload = loadHomePageContent;
