const searchButton = document.getElementById('search-button');
const resultsDiv = document.getElementById('results');

searchButton.addEventListener('click', async () => {
    const query = document.getElementById('search-query').value;
    const response = await fetch(`/api/search?query=${encodeURIComponent(query)}`);
    const data = await response.json();

    resultsDiv.innerHTML = '';
    data.items.forEach(item => {
        const video = document.createElement('div');
        video.innerHTML = `
            <h3>${item.snippet.title}</h3>
            <iframe width="560" height="315" src="https://www.youtube.com/embed/${item.id.videoId}" 
                frameborder="0" allow="autoplay; encrypted-media" allowfullscreen>
            </iframe>
        `;
        resultsDiv.appendChild(video);
    });
});
