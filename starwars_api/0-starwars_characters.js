#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const url = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(url, (error, response, body) => {
  if (error) return;

  const film = JSON.parse(body);
  const characters = film.characters;

  printCharacters(characters, 0);
});

function printCharacters (characters, index) {
  if (index >= characters.length) return;

  request(characters[index], (error, response, body) => {
    if (!error) {
      const character = JSON.parse(body);
      console.log(character.name);
      printCharacters(characters, index + 1);
    }
  });
}
