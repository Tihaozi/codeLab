# Python example
long_text = "My Long Text"
elided_text = long_text[5:] + "..."
# creates: My Lo...

text = "My Long Text"
if len(text) > 5:
   text = text[0:6] + "..."
print text

total_width = 100 # px
character_width = 10 # px
text = "My Long Text"  # 12 characters = 120 px
print len(text)
if len(text) * character_width > total_width:
    max_characters = int(total_width / character_width)
    text = text[max_characters - 3:] + "..."

print text