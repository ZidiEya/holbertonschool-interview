#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie_ID>');
  process.exit(1);
}

const url = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(url, function (error, response, body) {
  if (error) return console.error(error);

  const characters = JSON.parse(body).characters;

  const fetchCharacters = (index) => {
    if (index >= characters.length) return;

    request(characters[index], function (err, res, body) {
      if (err) return console.error(err);
      const name = JSON.parse(body).name;
      console.log(name);
      fetchCharacters(index + 1);
    });
  };

  fetchCharacters(0);
});
