const audioPlayer = document.getElementById("audioPlayer");

function playSong(lielement, songsrc) {
    document.querySelectorAll(".song").forEach(li => li.classList.remove("active")); 

    lielement.classList.add("active"); 
    audioPlayer.src = songsrc;
    audioPlayer.play();

    audioPlayer.onended = function() {
        lielement.classList.remove('active');
    };
}


document.querySelectorAll(".song").forEach(item => {
    item.addEventListener('click', function() {
        const songSrc = this.getAttribute('data-src'); 
        playSong(this, songSrc);
    });
});

document.querySelectorAll(" .fa-play").forEach(Item => {
    Item.addEventListener('click', function() {
        const songSrc = this.getAttribute('data-src'); 
        if (songSrc) {
            playSong(document.querySelector(`.song[data-src="${songSrc}"]`), songSrc);
        }
    });
});

