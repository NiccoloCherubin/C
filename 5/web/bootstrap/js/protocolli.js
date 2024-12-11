// Funzione per caricare i contenuti dal file JSON
async function loadProtocolliContent() {
    try {
        // Carica il file JSON
        const response = await fetch('json/protocolliContent.json');
        
        // Verifica che la risposta sia ok
        if (!response.ok) {
            throw new Error('Errore nel caricamento del file JSON');
        }

        // Converte la risposta in formato JSON
        const data = await response.json();

        // Imposta il contenuto dell'alert
        const alertContainer = document.getElementById('alert-container');
        alertContainer.innerHTML = `<strong>${data.alert.title}</strong> ${data.alert.message}`;

        // Crea le card con i protocolli
        const cardContainer = document.getElementById('card-container');
        data.cardContent.forEach((card) => {
            const cardElement = document.createElement('div');
            cardElement.classList.add('col-md-4');
            cardElement.innerHTML = `
                <div class="card">
                    <div class="card-body">
                        <h5 class="card-title">${card.title}</h5>
                        <p class="card-text">${card.description}</p>
                        <a href="${card.link}" target="_blank" class="btn ${card.buttonClass}">${card.linkText}</a>
                    </div>
                </div>
            `;
            cardContainer.appendChild(cardElement);
        });

        // Crea la tabella con i protocolli
        const tableBody = document.querySelector('#protocol-table tbody');
        data.tableData.forEach((row) => {
            const tableRow = document.createElement('tr');
            tableRow.innerHTML = `
                <td>${row.protocol}</td>
                <td>${row.description}</td>
                <td>${row.port}</td>
            `;
            tableBody.appendChild(tableRow);
        });

    } catch (error) {
        console.error("Errore nel caricamento dei contenuti:", error);
    }
}

// Carica i contenuti quando la pagina è pronta
window.onload = loadProtocolliContent;
