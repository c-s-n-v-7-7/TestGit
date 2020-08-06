const game = () => {
    let pScore = 0;
    let cSore = 0;

    const startGame = () =>{
        const playBtn = document.querySelector('.intro button');
        const introScreen = documentquerySelector('.intro');
        const match = document.querySelector('.match');

        playBtn.addEventListener("click",() =>PageTransitionEvent{
            introScreen,classList.add("fadeOut"),
            match.classList.add('fadeIn'),
        });

    };
startGame();
//updateScore();
}; 


game();