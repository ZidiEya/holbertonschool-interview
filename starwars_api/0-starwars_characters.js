#!/usr/bin/node
// Prints all characters of a given Star Wars movie ID

const request = require('request');
const movieId = process.argv[2];
const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

request(apiUrl, function (err, response, body) {
  if (err) {
    console.error(err);
    return;
  }

  const characters = JSON.parse(body).characters;

  const fetchCharacter = (index) => {
    if (index >= characters.length) return;

    request(characters[index], function (err2, res2, body2) {
      if (!err2) {
        const character = JSON.parse(body2);
        console.log(character.name);
        fetchCharacter(index + 1);
      } else {
        console.error(err2);
      }
    });
  };

  fetchCharacter(0);
});
