	function loadHome() {
		var contentRq 	= new XMLHttpRequest();
		var fwmRq		= new XMLHttpRequest();	
		var hostRq		= new XMLHttpRequest();
		var prodCodeRq	= new XMLHttpRequest();
		var roomIdRq	= new XMLHttpRequest();
		
		
		contentRq.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("content").innerHTML = this.responseText;
			}
		};
		fwmRq.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("fmw").innerHTML = this.responseText;
			}
		};
		hostRq.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("host").innerHTML = this.responseText;
			}
		};
		prodCodeRq.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("productCode").innerHTML = this.responseText;
			}
		};
		roomIdRq.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("room").innerHTML = this.responseText;
			}
		};
		
		contentRq.open	("GET", "/home", 			true);
		fwmRq.open		("GET", "/fmw", 			true);
		hostRq.open		("GET", "/host", 			true);
		prodCodeRq.open	("GET", "/productCode", 	true);
		roomIdRq.open	("GET", "/roomId", 			true);
		
		contentRq.send();
		fwmRq.send();
		hostRq.send();
		prodCodeRq.send();
		roomIdRq.send();
	};