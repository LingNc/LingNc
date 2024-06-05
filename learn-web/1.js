import XMLHttpRequest from "xmlhttprequest";

var xhr = new XMLHttpRequest();
var url = "https://example.com/api";
xhr.open("POST", url, true);
xhr.setRequestHeader("Content-Type", "application/json");
xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
        var json = JSON.parse(xhr.responseText);
        console.log(json);
    }
};
var data = JSON.stringify({ key: "value" });
xhr.send(data);