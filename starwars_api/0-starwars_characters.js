#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  process.exit();
}

const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(apiUrl, function (err, response, body) {
  if (err || response.statusCode !== 200) {
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  printCharacters(characters, 0);
});

function printCharacters (characters, index) {
  if (index >= characters.length) return;

  request(characters[index], function (err, response, body) {
    if (!err && response.statusCode === 200) {
      const character = JSON.parse(body);
      console.log(character.name);
      printCharacters(characters, index + 1);
    }
  });
}
