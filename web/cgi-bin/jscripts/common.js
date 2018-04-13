
/* 进度条刷新 配合jquery使用 */
$(function(){
  
  var interval = setInterval(increment,10);
  var current = 0;
  var t=3;
  function increment()
  {
    current++;
	if(current == 100) 
	{   
		clearInterval(interval);
		$('h1').html("配置成功!"); 
		interval = setInterval(counttime,1000);
		function counttime()
		{ 
			$('#config_status').html("----等待 "+t+"s 返回----"); 
			if(t==0)
			{
				clearInterval(interval);
				//location=document.referrer;
				location = "pi_config_1.htm";
			}
			t--;
		}
		
	}
    $('#counter').html(current+'%'); 
  }
});
/* 进度条刷新 */



/*导航栏*/

/*导航栏*/