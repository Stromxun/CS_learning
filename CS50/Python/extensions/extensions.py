str = input('File name: ').lower().strip()
pre, dot, last = str.rpartition('.')
if last == 'gif' or last == 'jpg' or last == 'jpeg' or last == 'png':
    last = 'jpeg' if last == 'jpg' else last
    print('image/' + last)
elif last == 'pdf' or last == 'zip':
    print('application/' + last)
elif last == 'txt':
    print('text/plain')
else:
    print('application/octet-stream')
