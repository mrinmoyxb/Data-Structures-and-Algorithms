const API = "https://dogapi.dog/api/v2/breeds";

async function getData(){
    console.log("Fetching data");
    let response = await fetch(API);
    console.log("Fetched data");
    let data = response.json();
    console.log(response.status);
}

getData();