const audioPlayer = document.getElementById("audioPlayer");

function playSong(lielement, songsrc) {
    document.querySelectorAll("li").forEach(li => li.classList.remove("active")); // Corrected classList

    lielement.classList.add("active");
    audioPlayer.src = songsrc;
    audioPlayer.play();

    audioPlayer.onended = function() {
        lielement.classList.remove('active'); // Corrected 'liElement' to 'lielement'
    };
}

// Event listeners for each song
document.getElementById("song1").addEventListener('click', function() {
    playSong(this, 'Songs/ Last Paradise.mp3');
});

document.getElementById("song2").addEventListener('click', function() {
    playSong(this, 'Songs/ Your Gonna Miss Me.mp3');
});

document.getElementById("song3").addEventListener('click', function() {
    playSong(this, 'Songs/Fragile.mp3');
});

document.getElementById("song4").addEventListener('click', function() {
    playSong(this, "Songs/GUV'NOR .mp3");
});

document.getElementById("song5").addEventListener('click', function() {
    playSong(this, 'Songs/Hurrican Dorothy.mp3');
});

document.getElementById("song6").addEventListener('click', function() {
    playSong(this, 'Songs/Kiwi .mp3');
});

document.getElementById("song7").addEventListener('click', function() {
    playSong(this, "Songs/Libet's Delay.mp3");
});

document.getElementById("song8").addEventListener('click', function() {
    playSong(this, 'Songs/Mayonaka No Door.mp3'); // Fixed 'aplaySong' to 'playSong'
});

document.getElementById("song9").addEventListener('click', function() {
    playSong(this, 'Songs/New Person, Same Old Mistakes .mp3');
});

document.getElementById("song10").addEventListener('click', function() {
    playSong(this, 'Songs/Will He.mp3');
});

document.getElementById("song11").addEventListener('click', function() {
    playSong(this, 'Songs/Important Podcast.mp3');
});
