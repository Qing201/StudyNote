txt_path = "Small_Project/Content/test.txt"

with open(txt_path, 'r', encoding='utf-8') as txt:
    lines = txt.readlines()
    for i, line in enumerate(lines):
        pline = line.split(None, maxsplit=-1)
        level = pline[0]; title = ' '.join(pline[1:len(pline)-1]); page = int(pline[len(pline)-1])
        print(" * level: %s, title: %s, page: %d" % (level, title, page))
        