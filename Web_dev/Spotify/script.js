document.querySelectorAll(".player").forEach(i => {
    i.addEventListener("click", function(){
        const playIcon = this.querySelector("#play");
        
        if (playIcon.classList.contains("fa-play")) {
            playIcon.classList.remove("fa-play");
            playIcon.classList.add("fa-pause");
            audioPlayer.play();
        } else {
            playIcon.classList.remove("fa-pause");
            playIcon.classList.add("fa-play");
            audioPlayer.pause();
        }
    });
});
const audioPlayer = document.getElementById("audioPlayer");

function playSong(lielement, songsrc) {
    document.querySelectorAll(".song").forEach(li => li.classList.remove("active")); 

    lielement.classList.add("active"); 
    audioPlayer.src = songsrc;
    audioPlayer.play();
    const player = document.querySelector(".player");
    if (player) {
        const playIcon = player.querySelector("#play");
        playIcon.classList.remove("fa-play");
        playIcon.classList.add("fa-pause");
    }


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

