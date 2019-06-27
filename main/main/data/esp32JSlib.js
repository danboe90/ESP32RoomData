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
	
	function loadRoom() {
		var myRequest = new XMLHttpRequest();
		var roomIdRq	= new XMLHttpRequest();
		
		myRequest.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("content").innerHTML = this.responseText;
			}
		};
		roomIdRq.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("room").value = this.responseText;
			}
		};
		
		myRequest.open	("GET", "/roomSettings", 	true);
		roomIdRq.open	("GET", "/roomId", 			true);
		
		myRequest.send();
		roomIdRq.send();
	};
	
	function loadWifi() {
		var myRequest = new XMLHttpRequest();
		
		myRequest.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("content").innerHTML = this.responseText;
			}
		};
		myRequest.open("GET", "/wifiSettings", true);
		myRequest.send();
	};
		
	function loadLora() {
		var myRequest = new XMLHttpRequest();
		
		myRequest.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("content").innerHTML = this.responseText;
			}
		};
		myRequest.open("GET", "/loraSettings", true);
		myRequest.send();
	};
	
	function loadBT() {
		var myRequest = new XMLHttpRequest();
		
		myRequest.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("content").innerHTML = this.responseText;
			}
		};
		myRequest.open("GET", "/btSettings", true);
		myRequest.send();
	};
	
	function loadI2C() {
		var myRequest = new XMLHttpRequest();
		
		myRequest.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				document.getElementById("content").innerHTML = this.responseText;
			}
		};
		myRequest.open("GET", "/i2cSettings", true);
		myRequest.send();
	};
	
	function loadContent(page) {
	
		if(page === 0) { loadHome(); }		
		if(page === 1) { loadRoom(); }		// room settings
		if(page === 2) { loadWifi(); }		// wifiSettings
		if(page === 3) { loadLora(); }		// lora Settings
		if(page === 4) { loadBT();   }		// bluetooth setings
		if(page === 5) { loadI2C();  }		// i2c setings
	};
	
	
	function updateRoomData() {
		
		var RoomId 		= document.getElementById("room").value;
		var RoomName 	= document.getElementById("roomname"). value;
		
		var params		= JSON.stringify({id: RoomId, name: RoomName})
		
		var myRequest = new XMLHttpRequest();
		
		myRequest.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				// document.getElementById("content").innerHTML = this.responseText;
			}
		};
		myRequest.open("POST", "/updateRoom", true);
		myRequest.setRequestHeader("Content-Type", "application/json");
		myRequest.setRequestHeader("Content-length", params.length);
		myRequest.setRequestHeader("Connection", "close");
		console.log(params);
		myRequest.send(params);
	};
	