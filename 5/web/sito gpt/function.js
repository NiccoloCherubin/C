// Inizializzazione delle variabili del timer
let countdown;
let remainingTime = 600; // Tempo in secondi (10 minuti)

function startCountdown() {
    const timerElement = document.getElementById('timer-display');

    remainingTime = parseInt(localStorage.getItem('remainingTime')) || 600;

    timerElement.innerText = `${Math.floor(remainingTime / 60)}:${(remainingTime % 60).toString().padStart(2, '0')}`;

    countdown = setInterval(() => {
        if (remainingTime <= 0) {
            clearInterval(countdown);
            localStorage.removeItem('remainingTime');
            autoSaveAnswers();
            alert("Tempo esaurito! Le risposte sono state salvate.");
            location.href = "home.html";
        } else {
            remainingTime--;
            localStorage.setItem('remainingTime', remainingTime);
            timerElement.innerText = `${Math.floor(remainingTime / 60)}:${(remainingTime % 60).toString().padStart(2, '0')}`;
        }
    }, 1000);
}

async function loadQuestions() {
    const response = await fetch('questions.json');
    return await response.json();
}

function saveAnswer(questionId, answer) {
    const answers = JSON.parse(localStorage.getItem('answers')) || {};  // Se non ci sono risposte, inizializza un oggetto vuoto
    answers[questionId] = answer;  // Salva la risposta associandola all'ID della domanda
    localStorage.setItem('answers', JSON.stringify(answers));  // Salva di nuovo nel localStorage
    updateAnswerCounter();  // Aggiorna il contatore delle risposte
}


function getSavedAnswer(questionId) {
    const answers = JSON.parse(localStorage.getItem('answers')) || {};
    return answers[questionId] || '';
}

function updateAnswerCounter() {
    const answers = JSON.parse(localStorage.getItem('answers')) || {};
    const totalAnswered = Object.keys(answers).length;
    document.getElementById('answer-counter').innerText = `${totalAnswered}/5`;
}

function navigateTo(type, questionId) {
    location.href = type === 'open' ? `open_question.html?id=${questionId}` : `multiple_choice.html?id=${questionId}`;
}

function autoSaveAnswer(type) {
    const questionId = new URLSearchParams(window.location.search).get('id');
    let answer = '';
    if (type === 'open') {
        answer = document.getElementById('answer-box').value;
    } else {
        answer = document.querySelector('input[name=answer]:checked')?.value;
    }
    saveAnswer(questionId, answer);
}

async function initializePage(type) {
    const urlParams = new URLSearchParams(window.location.search);
    const questionId = urlParams.get('id');

    if (!questionId) {
        alert("Errore: ID domanda mancante! Sarai reindirizzato alla home.");
        location.href = 'home.html';
        return;
    }    

    const questions = await loadQuestions();

    let question, index;
    if (type === 'open') {
        question = questions.open_questions.find(q => q.id === parseInt(questionId));
        index = questions.open_questions.findIndex(q => q.id === parseInt(questionId));
    } else {
        question = questions.multiple_choice.find(q => q.id === questionId);
        index = questions.multiple_choice.findIndex(q => q.id === questionId);
    }

    if (!question) {
        alert("Domanda non trovata! Sarai reindirizzato alla home.");
        location.href = 'home.html';
        return;
    }

    if (type === 'open') {
        document.getElementById('question-text').innerText = question.text;
        document.getElementById('answer-box').value = getSavedAnswer(questionId);
        document.getElementById('answer-box').addEventListener('input', () => autoSaveAnswer(type));
    } else {
        document.getElementById('question-text').innerText = question.text;

        const optionsContainer = document.getElementById('options-list');
        optionsContainer.innerHTML = '';
        question.options.forEach(option => {
            const radioButton = document.createElement('input');
            radioButton.type = 'radio';
            radioButton.name = 'answer';
            radioButton.value = option;
            if (option === getSavedAnswer(questionId)) radioButton.checked = true;
            radioButton.addEventListener('change', () => autoSaveAnswer(type));

            const label = document.createElement('label');
            label.innerText = option;
            optionsContainer.appendChild(radioButton);
            optionsContainer.appendChild(label);
            optionsContainer.appendChild(document.createElement('br'));
        });
    }

    setupNavigationButtons(type, questionId, questions);
}

function setupNavigationButtons(type, questionId, questions) {
    const prevButton = document.getElementById('previous');
    const nextButton = document.getElementById('next');
    const counterElement = document.getElementById('answer-counter');

    const allQuestions = [
        ...questions.open_questions.map(q => ({ ...q, type: 'open' })),
        ...questions.multiple_choice.map(q => ({ ...q, type: 'multiple' }))
    ];

    const currentQuestion = allQuestions.find(q => q.type === type && q.id == questionId);
    const globalIndex = allQuestions.indexOf(currentQuestion);

    counterElement.innerText = `${globalIndex + 1}/${allQuestions.length}`;

    if (globalIndex > 0) {
        const previousQuestion = allQuestions[globalIndex - 1];
        prevButton.onclick = () => navigateTo(previousQuestion.type, previousQuestion.id);
        prevButton.disabled = false;
    } else {
        prevButton.disabled = true;
    }

    if (globalIndex < allQuestions.length - 1) {
        const nextQuestion = allQuestions[globalIndex + 1];
        nextButton.onclick = () => navigateTo(nextQuestion.type, nextQuestion.id);
        nextButton.disabled = false;
    } else {
        nextButton.disabled = true;
    }
}

async function gradeTest() {
    const questions = await loadQuestions();
    const userAnswers = JSON.parse(localStorage.getItem('answers')) || {};

    let correctAnswers = 0;

    questions.multiple_choice.forEach(question => {
        if (userAnswers[question.id] === question.correct) {
            correctAnswers++;
        }
    });

    alert(`Hai totalizzato ${correctAnswers}/${questions.multiple_choice.length} risposte corrette.`);
    localStorage.clear();
    remainingTime = 600;
    clearInterval(countdown);
    location.href = 'home.html';
}
function esportaRisposte() {
    const risposte = JSON.parse(localStorage.getItem("answers"));

    if (!risposte) {
        alert("Non ci sono risposte salvate.");
        return;
    }

    // Crea un blob con il contenuto in formato JSON
    const blob = new Blob([JSON.stringify(risposte, null, 2)], { type: 'application/json' });

    // Crea un link temporaneo per il download del file
    const link = document.createElement('a');
    link.href = URL.createObjectURL(blob);
    link.download = 'risposte.json';  // Nome del file da scaricare

    // Simula il clic sul link per avviare il download
    link.click();
}
document.addEventListener("DOMContentLoaded", function() {
    // Seleziona il pulsante tramite l'ID
    const exportButton = document.getElementById('esporta-risposte');
    
    // Aggiungi un event listener per il clic sul pulsante
    exportButton.addEventListener('click', esportaRisposte);
});

function esportaRisposte() {
    // Recupera le risposte salvate nel localStorage
    const risposte = JSON.parse(localStorage.getItem("answers"));

    if (!risposte) {
        alert("Non ci sono risposte salvate.");
        return;
    }

    // Crea un blob con il contenuto in formato JSON
    const blob = new Blob([JSON.stringify(risposte, null, 2)], { type: 'application/json' });

    // Crea un link temporaneo per il download del file
    const link = document.createElement('a');
    link.href = URL.createObjectURL(blob);
    link.download = 'risposte.json'; // Nome del file da scaricare

    // Simula il clic sul link per avviare il download
    link.click();
}

// Funzione per creare il file JSON
function downloadJSON() {
    let risposteJson = {};

    // Raccogli le risposte salvate
    for (let i = 0; i < domande.length; i++) {
        const risposta = localStorage.getItem(`risposta_${i}`);
        if (risposta) {
            risposteJson[`domanda_${i + 1}`] = risposta;
        }
    }

    // Converte l'oggetto in una stringa JSON
    const jsonString = JSON.stringify(risposteJson, null, 2);

    // Crea un blob con i dati JSON
    const blob = new Blob([jsonString], { type: 'application/json' });

    // Crea un URL per il blob
    const url = URL.createObjectURL(blob);

    // Crea un link per il download
    const a = document.createElement('a');
    a.href = url;
    a.download = 'risposte.json';

    // Simula il clic sul link per avviare il download
    a.click();

    // Libera l'URL creato
    URL.revokeObjectURL(url);
}

// Event listener per il pulsante di download
document.getElementById('download').addEventListener('click', downloadJSON);





