// Funzione per caricare i contenuti dal file JSON
async function loadPilaOsiContent() {
    try {
        // Carica il file JSON
        const response = await fetch('json/pilaOsiContent.json');
        
        // Verifica che la risposta sia ok
        if (!response.ok) {
            throw new Error('Errore nel caricamento del file JSON');
        }

        // Converte la risposta in formato JSON
        const data = await response.json();

        // Imposta il titolo della pagina
        document.getElementById('page-title').textContent = data.alert.title;

        // Imposta il contenuto dell'alert
        const alertContainer = document.getElementById('alert-container');
        alertContainer.innerHTML = `<strong>${data.alert.title}</strong> ${data.alert.message}`;

        // Imposta la card di introduzione
        const introCard = document.getElementById('intro-card');
        introCard.innerHTML = `
            <div class="card-body">
                <h5 class="card-title">${data.introCard.title}</h5>
                <p class="card-text">${data.introCard.text}</p>
            </div>
        `;

        // Crea l'accordion per descrivere i livelli
        const accordionContainer = document.getElementById('accordionOSI');
        data.levels.forEach((level, index) => {
            const accordionItem = document.createElement('div');
            accordionItem.classList.add('accordion-item');
            accordionItem.innerHTML = `
                <h2 class="accordion-header" id="heading${index}">
                    <button class="accordion-button ${index !== 0 ? 'collapsed' : ''}" type="button" data-bs-toggle="collapse" data-bs-target="#collapse${index}" aria-expanded="${index === 0 ? 'true' : 'false'}" aria-controls="collapse${index}">
                        Livello ${index + 1}: ${level.name}
                    </button>
                </h2>
                <div id="collapse${index}" class="accordion-collapse collapse ${index === 0 ? 'show' : ''}" aria-labelledby="heading${index}" data-bs-parent="#accordionOSI">
                    <div class="accordion-body">
                        ${level.description}
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
window.onload = loadPilaOsiContent;
