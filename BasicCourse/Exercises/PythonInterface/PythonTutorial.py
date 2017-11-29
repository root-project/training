
def count(text):
  """Count the number of words in a text."""
  words = text.split()
  return len(words)

def find(text, word):
  """Check if a word is present in a text."""
  words = text.split()
  for w in words:
    if w == word:
      return True
  return False


if __name__ == '__main__':
  text = """
Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.
"""
  word = 'magna'

  print('Number of words in the text: ' + str(count(text)))
  print('Is magna in the text: ' + str(find(text, word)))
