#!/usr/bin/python
import sys
import os
import PIL
from PIL import Image

f = open('_tmp', 'r')
fl = f.readlines()
f.close()

f = open(sys.argv[1].strip('/') + '.xml', 'w')
print >> f, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
print >> f, "<data><basedir>"+ sys.argv[1] + '/' +"</basedir><entries>"
for l in fl:
	t=l.strip()
	print 'processing .. ', t,
	if t == "_tmp":
		print 'skipping'
		continue

	ratio = 0.05
	#basewidth = 400
	os.system('identify -verbose ' + t + ' |grep "exif:" | grep -e "exif:MaxApertureValue:" -e "exif:ISOSpeedRatings:" -e "exif:ExposureTime:" > .exif')
	d = open (".exif", 'r')
	desc = ',  '.join([x.strip()[5:] for x in d.readlines()])
	print desc
	d.close()
	os.system('rm .exif')

	img = Image.open(t)
	w, h = img.size[:2]
	hsize = h * ratio
	wsize = w * ratio
	#wpercent = (basewidth/float(w))
	#hsize = int((float(h)*float(wpercent)))
	#img = img.resize((basewidth,hsize), PIL.Image.ANTIALIAS)
	img = img.resize((w, h), PIL.Image.ANTIALIAS)
	img.save(t) 
	img.thumbnail((320, 320), PIL.Image.ANTIALIAS)
	img.save('thumb-'+t) 


	print >> f, "<entry>",
	print >> f, "<thumb>", 'thumbs/thumb-'+t, "</thumb>",
	print >> f, "<height>", int(hsize), "</height>",
	print >> f, "<width>", int(wsize), "</width>",
	print >> f, "<description>", desc, "</description>",
	print >> f, "<image>", t, "</image>",
	print >> f, "</entry>"

print >> f, "</entries></data>"

f.close()

