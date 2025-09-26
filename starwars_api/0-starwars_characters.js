#!/usr/bin/node
// Script to print all characters of a Star Wars movie
// Usage: ./0-starwars_characters.js <movie_id>

const request = require('request');

if (process.argv.length !== 3) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const movieId = process.argv[2];
const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, { json: true }, (err, res, body) => {
  if (err) {
    console.error(err);
    return;
  }

  if (res.statusCode !== 200) {
    console.error(`Error: Status code ${res.statusCode}`);
    return;
  }

  const characters = body.characters;

  // Function to fetch each character recursively to preserve order
  const fetchCharacter = (index) => {
    if (index >= characters.length) return;

    request(characters[index], { json: true }, (err2, res2, charBody) => {
      if (!err2 && res2.statusCode === 200) {
        console.log(charBody.name);
        fetchCharacter(index + 1);
      }
    });
  };

  fetchCharacter(0);
});
