from random import randint

madlibs = ("Once upon a {}, there was a boy named Alfred who decided to build a {} tree house." + 
          "He {} through his yard and picked up all the spare pieces of {} that he could find." +
          "He {} small ones and big onces and piled them all up near the oak tree." +
          "He figured he would also need {} and a hammer to assemble his tree house." +
          "He went to his father's workshop and found a good sized hammer that he could use." +
          "He {} in the drawer and finally found a {} of nails."+
          "He brought everything back with him to the {} and started building his {} house." +
          "By supper time, Alfred was tried, but he was {} of his work." +
          "The tree house looked {}. "+
          "Now, all he had to do was put it up in the tree." +
          "Maybe his dad could {} with that.")

def get(word):
    possible_words = {
    'noun' : ['water','salt','fish','coffee','nails','taxi','dog','truck','time','wood','found'],
    'adjective' : ['cool','messy','mischievous','garrulous','attractive','angry','big','nervous','polite','tall','scary'],
    'verb' : ['accept','enjoy','love','identity','agree','go','grow','climb','buy','eat','ate','drink','learn','lose','manage']
    }
    words = possible_words[word]
    length = len(words) - 1
    index = randint(0, length)
    return words.pop(index)

def create():
    return madlibs.format(
        get('noun'),
        get('adjective'),
        get('verb'),
        get('noun'),
        get('verb'),
        get('noun'),
        get('verb'),
        get('noun'),
        get('noun'),
        get('adjective'),
        get('adjective'),
        get('adjective'),
        get('verb'),
    )

i = 1
for x in range(5):
    print(f"\n\nStory {i}:\n")
    print(create())
    i += 1
