//! setTimeout is asynchronus
function syncAsync(){
    console.log("one");
    console.log("two");

    setTimeout(()=>{
        console.log("Hello, executed after 2s");
    }, 2000);

    console.log("three");
    console.log("four");
}

//! callback and callback hell: if we want our program to print one after another.
//! async but in an order
function callbackHell(dataId, getNextData){
    setTimeout(()=>{
        console.log("data: ", dataId);
        if(getNextData){
            getNextData();
        }
    }, 2000);
}

// callbackHell(1, ()=>{
//     callbackHell(2, ()=>{
//         callbackHell(3);
//     })
// })

//! promises
function promiseFunction(){
    return new Promise((resolve, reject)=>{
        console.log("promise call");
        // reject("error");
        resolve("success");
    });
};
// promiseFunction()
//     .then((res)=>{
//         console.log("promise function executed: ", res);
//     })
//     .catch((rej)=>{
//         console.log("promise rejected: ", rej);
// });

//! promises and setTimeout()
function async1(data){
    return new Promise((resolve, reject)=>{
        setTimeout(()=>{
            console.log("data received: ", data);
            resolve(data*2);
        }, 2000);
    });
}

function async2(data){
    return new Promise((resolve, reject)=>{
        setTimeout(()=>{
            console.log("data received: ", data);
            resolve("done");
        }, 4000);
    })
}

// console.log("promise chaining ...");
// async1(123)
//     .then((res)=>{
//         console.log("data fetched from async1: ", res);
//         console.log("calling async2");
//         async2(res)
//             .then((res)=>{
//                 console.log("data fetched from async2: ", res);
//             })
//     })
//     .catch((res)=>{
//         console.log("data not fetched ");
//     })

function callAsync(data){
    return new Promise((resolve, reject)=>{
        setTimeout(()=>{
            console.log("async function called");
            resolve("h4ack123--"+data);
        }, 2000);
    })
}

async function myFunc(){
    console.log("async-await...1");
    let response1 = await callAsync(456); // it will execute this async operation first
    console.log("response1: ", response1);

    console.log("\nasync-await...2");
    let response2 = await callAsync(789); // it will execute this async operation after first
    console.log("response2: ", response2);
}

myFunc();