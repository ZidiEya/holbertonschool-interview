#!/usr/bin/python3
"""
Recursive function that queries the Reddit API and counts keyword occurrences.
"""

import requests


def count_words(subreddit, word_list, word_count=None, after=None):
    if word_count is None:
        word_count = {}

        # Normalize word_list into a dict with lowercase keys and summed counts
        for word in word_list:
            key = word.lower()
            word_count[key] = word_count.get(key, 0) + 1

    headers = {'User-Agent': 'HolbertonSchoolProject/1.0'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'after': after, 'limit': 100}

    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)
        if response.status_code != 200:
            return
        data = response.json()
    except Exception:
        return

    # Extract titles and count keywords
    posts = data.get('data', {}).get('children', [])
    for post in posts:
        title = post.get('data', {}).get('title', '').lower().split()
        for word in title:
            # Remove word if it has attached punctuation
            if word.isalpha() and word in word_count:
                word_count[word] += 1

    # Recurse if more pages
    after = data.get('data', {}).get('after')
    if after:
        return count_words(subreddit, word_list, word_count, after)

    # All recursion done - process and print results
    sorted_counts = sorted(
        [(word, count) for word, count in word_count.items() if count > word_list.count(word)],
        key=lambda x: (-x[1], x[0])
    )

    for word, count in sorted_counts:
        print(f"{word}: {count}")
