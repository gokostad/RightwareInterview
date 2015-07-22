TEMPLATE = subdirs  
SUBDIRS += app \
           libmain \
           test

app.depends = libmain
test.depends = libmain
