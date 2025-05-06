#!/usr/bin/python3
"""Recursive function to count keyword occurrences in Reddit hot articles"""
import requests


def count_words(subreddit, word_list, word_count=None, after=None):
    """Recursively queries Reddit API and counts keyword occurrences in titles."""
    if word_count is None:
        word_count = {}

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "Mozilla/5.0"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    try:
        response = requests.get(url, headers=headers, params=params, allow_redirects=False)
        if response.status_code != 200:
            return

        data = response.json()
        posts = data.get("data", {}).get("children", [])
        after = data.get("data", {}).get("after", None)

        for post in posts:
            title = post.get("data", {}).get("title", "").lower().split()
            for word in word_list:
                count = title.count(word.lower())
                if count > 0:
                    word_lower = word.lower()
                    if word_lower in word_count:
                        word_count[word_lower] += count
                    else:
                        word_count[word_lower] = count

        if after is not None:
            return count_words(subreddit, word_list, word_count, after)
        else:
            # Filter out 0 counts and sort
            filtered = {k: v for k, v in word_count.items() if v > 0}
            for word in sorted(filtered.items(), key
