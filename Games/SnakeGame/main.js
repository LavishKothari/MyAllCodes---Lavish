var context;
var snake;
var canvas;
var interval;
var food;
var score=0;

window.onload=function() {
	
	canvas=document.getElementById("mycanvas");
	context=canvas.getContext("2d");
	context.lineWidth=0.5;	
	//setInterval(moveSnake,100);	
	
	snake = Snake.create();
	snake.drawSnake();
	interval = setInterval(fun,50);
	food = Food.create();	
	food.generateFood();		
}


window.onkeyup = function(e) {
	if(e.keyCode === 38 && snake.headDir !=3)
		snake.headDir = 2;
	if(e.keyCode === 40 && snake.headDir !=2)
		snake.headDir = 3;
	if(e.keyCode === 37 && snake.headDir !=1)
		snake.headDir =0;
	if(e.keyCode === 39 && snake.headDir !=0)
		snake.headDir = 1;
}

function fun() {
	snake.moveSnake();	
}

var Food = {
	x:-1,y:-1,
	create:function() {
		var obj=Object.create(this);
        return obj;	
	},
	generateFood:function() {
		while(1)
		{
			var newx=Math.floor(Math.random()*canvas.width);
			var newy=Math.floor(Math.random()*canvas.width);
			newx=Math.floor(newx/5)*5;
			newy=Math.floor(newy/5)*5;
			for(var i=0; i<snake.body.length; i++) {
				if(snake.body[i].start!=newx || snake.body[i].end!=newy) {
					this.x=newx;
					this.y=newy;
					context.fillRect(newx,newy,5,5);
					return;
				}
			}
		}
	}
	

};

var Snake = {
	body:[],
	width:0,
	headDir:1,
	create:function() {
        this.width=5;
        var obj=Object.create(this);
        var x=100;
        var y=100;
		for(var i=0; i<7; i++) {
	  		obj.body.push({start:x,end:y}); 
	  		x+=this.width;
 		}
        return obj;
    },  
    drawSnake:function() {
    	context.clearRect(0,0,canvas.width,canvas.height);
    	for(var i=0; i<this.body.length ;i++) 
    		context.fillRect(this.body[i].start,this.body[i].end,this.width,this.width);
    },
	moveSnake:function() {
		var n=this.body.length;
		var x=this.body[n-1].start;
		var y=this.body[n-1].end;
		var newx,newy;
		
		if(this.headDir===0) {
			newx=(x-this.width+canvas.width)%canvas.width;
			newy=y;
		}
		if(this.headDir===1) {
			newx=(x+this.width+canvas.width)%canvas.width;
			newy=y;
		}
		if(this.headDir===2) {
			newx=x;
			newy=(y-this.width+canvas.height)%canvas.height;
		}
		if(this.headDir===3) {
			newx=x;
			newy=(y+this.width+canvas.height)%canvas.height;
		}
		
		for(var i=0; i<n; i++) {
			if(this.body[i].start===newx && this.body[i].end===newy) {
				alert("game over");
				clearInterval(interval);
			}
		}
		this.body.push({start:newx,end:newy});
		if(newx===food.x && newy===food.y) {
			context.fillRect(newx,newy,this.width,this.width);
			food.generateFood();
			score++;
			document.getElementById("scorespan").innerHTML="Score = "+score;
		}
		else {
			context.fillRect(newx,newy,this.width,this.width);
			context.clearRect(this.body[0].start,this.body[0].end,this.width,this.width);
			this.body.splice(0,1);
		}			
	}
};


/*
	score
	level
		on incrementing level increase snake speed
		
*/



