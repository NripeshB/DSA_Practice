
function formatViews(views) {
    if (views >= 1_000_000_000) {
        return (views / 1_000_000_000).toFixed(1) + 'b';
    } else if (views >= 1_000_000) {
        return (views / 1_000_000).toFixed(1) + 'm';
    } else if (views >= 1_000) {
        return (views / 1_000).toFixed(1) + 'k';
    } else {
        return views;
    }
}

function Cardcreate() {
    let thumbnail = prompt("Enter the URL to the thumbnail:");
    let views = prompt("Enter the number of views in the video:");
    let title = prompt("Enter the title of the video:");
    let time = prompt("Enter the time it was uploaded (e.g., 2 months ago):");
    let duration = prompt("Enter the duration of the video:");

    document.getElementsByClassName("thumbnail")[0].src = thumbnail;
    document.getElementsByClassName("views")[0].innerHTML = formatViews(Number(views));
    document.getElementsByClassName("title")[0].innerHTML = title;
    document.getElementsByClassName("days")[0].innerHTML = time;
    document.getElementsByClassName("duration")[0].innerHTML = duration;
}

Cardcreate();
