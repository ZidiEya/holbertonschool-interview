#!/usr/bin/node

const request = require('request');

const asyncGetChar = async function (url) {
  return new Promise(function (resolve, reject) {
    request(url, function (err, res, body) {
      if (!err && res.statusCode === 200) {
        resolve(body);
      } else {
        reject(err);
      }
    });
  });
};

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2],
  function (err, res, body) {
    if (err) { console.log(err); }
    const jsn = JSON.parse(body);
    const chars = jsn.characters;
    (async function () {
      for (let i = 0; i < chars.length; i++) {
        const res = await asyncGetChar(chars[i]);
        const name = JSON.parse(res);
        console.log(name.name);
      }
    })();
  }
);
