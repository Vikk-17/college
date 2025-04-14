"""
# Write a Python program using Pandas to clean and transform a dataset containing social media posts with noisy text. Apply regular expressions to:
# Remove hashtags, mentions, and URLs
# Convert text to lowercase
# Remove special characters
# Encourage students to explore NLTK or spaCy for future enhancements.
"""

import pandas as pd
import re


file_path = "/content/social_media_noisy_100.csv"
df = pd.read_csv(file_path)


# Load the dataset
df = pd.read_csv("social_media_noisy_100.csv")

# Function to clean a social media post
def clean_post(text):
    text = str(text)
    text = re.sub(r'http\S+|www\.\S+', '', text)  # remove URLs
    text = re.sub(r'@\w+', '', text)              # remove mentions
    text = re.sub(r'#\w+', '', text)              # remove hashtags
    text = text.lower()                           # convert to lowercase
    text = re.sub(r'[^a-z\s]', '', text)          # remove special characters and numbers
    text = re.sub(r'\s+', ' ', text).strip()      # remove extra whitespace
    return text

# Apply cleaning
df['cleaned_post'] = df['post'].apply(clean_post)

# Save cleaned dataset
df.to_csv("cleaned_social_media_posts.csv", index=False)

# Display a few cleaned samples
print(df[['post', 'cleaned_post']].head())



import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

nltk.download('punkt')
nltk.download('stopwords')
nltk.download('punkt_tab')

def remove_stopwords(text):
    tokens = word_tokenize(text)
    clean_tokens = [t for t in tokens if t not in stopwords.words('english')]
    return " ".join(clean_tokens)

df['no_stopwords'] = df['cleaned_post'].apply(remove_stopwords)


#using spaCy
import spacy

# Load spaCy English model
nlp = spacy.load("en_core_web_sm")

# Load dataset
df = pd.read_csv("social_media_noisy_100.csv")

# Custom text cleaner using spaCy
def clean_with_spacy(text):
    text = str(text)

    # Remove URLs, mentions, and hashtags using regex
    text = re.sub(r'http\S+|www\.\S+', '', text)  # remove URLs
    text = re.sub(r'@\w+', '', text)              # remove mentions
    text = re.sub(r'#\w+', '', text)              # remove hashtags

    doc = nlp(text.lower())  # lowercase and process with spaCy

    # Filter tokens: remove stop words, punctuations, and short tokens
    tokens = [
        token.lemma_ for token in doc
        if not token.is_stop and not token.is_punct and not token.like_url and len(token.text) > 2
    ]

    return " ".join(tokens)

# Apply spaCy cleaner
df["spacy_cleaned_post"] = df["post"].apply(clean_with_spacy)

# Save to new CSV
df.to_csv("spacy_cleaned_social_media_posts.csv", index=False)

# Show sample
print(df[["post", "spacy_cleaned_post"]].head())

