#!/usr/bin/node

const request = require('request');

// Get movie ID from command line arguments
const movieId = process.argv[2];

// Check if movie ID is provided
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

// Star Wars API base URL
const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

// Func to fetch character name from URL
function getCharacterName(characterUrl) {
  return new Promise((resolve, reject) => {
    request(characterUrl, (error, response, body) => {
      if (error) {
        reject(error);
        return;
      }
      
      if (response.statusCode !== 200) {
        reject(new Error(`Failed to fetch character: ${response.statusCode}`));
        return;
      }
      
      try {
        const character = JSON.parse(body);
        resolve(character.name);
      } catch (parseError) {
        reject(parseError);
      }
    });
  });
}

// Fetch the movie data
request(apiUrl, async (error, response, body) => {
  if (error) {
    console.error('Error fetching movie data:', error.message);
    process.exit(1);
  }
  
  if (response.statusCode !== 200) {
    console.error(`Error: Movie with ID ${movieId} not found`);
    process.exit(1);
  }
  
  try {
    const movie = JSON.parse(body);
    const characterUrls = movie.characters;
    
    // Fetch all character names in order
    for (const characterUrl of characterUrls) {
      try {
        const characterName = await getCharacterName(characterUrl);
        console.log(characterName);
      } catch (charError) {
        console.error('Error fetching character:', charError.message);
      }
    }
  } catch (parseError) {
    console.error('Error parsing movie data:', parseError.message);
    process.exit(1);
  }
});
