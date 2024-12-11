// Funzione per caricare e visualizzare il contenuto del glossario
async function loadGlossario() {
    try {
        // Effettua una richiesta al file JSON
        const response = await fetch("json/glossario.json");

        // Verifica che la risposta sia ok
        if (!response.ok) {
            throw new Error("Errore nel caricamento del file JSON");
        }

        // Converte la risposta in formato JSON
        const data = await response.json();

        // Seleziona il contenitore del glossario
        const container = document.getElementById("glossario-container");

        // Itera sui termini e aggiunge ogni termine alla pagina
        data.glossario.forEach(term => {
            // Crea il link del termine
            const termElement = document.createElement("a");
            termElement.href = term.link;
            termElement.classList.add("list-group-item", "list-group-item-action", term.classe);

            // Aggiungi il termine e la descrizione
            termElement.innerHTML = `<strong>${term.termine}</strong> - ${term.descrizione}`;

            // Aggiungi l'elemento al contenitore
            container.appendChild(termElement);
        });
    } catch (error) {
        console.error("Errore nel caricamento del glossario:", error);
    }
}

// Chiama la funzione per caricare il glossario quando la pagina è pronta
window.onload = loadGlossario;
