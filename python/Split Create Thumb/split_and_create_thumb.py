from os import listdir, rename
from os.path import isfile, join
from PIL import Image

sourcepath = 'input'
destinationpath = 'output'

files = [f for f in listdir(sourcepath) if isfile(join(sourcepath, f))]

last_saved_page = 0


def create_thumbs_and_save(img,imgwidth,imgheight,number,file):
    img.save(join(destinationpath,str(number)+'-large.jpg'))

    small = img.resize((int(imgwidth/imgheight*650),650))
    small.save(join(destinationpath,str(number)+'.jpg'))

    thumb = img.resize((int(imgwidth/imgheight*100),100))
    thumb.save(join(destinationpath,str(number)+'-thumb.jpg'))



def split(file):
    global last_saved_page
    img = Image.open(join(sourcepath,file))
    imgwidth, imgheight = img.size
    if(imgheight<imgwidth):
        leftbox = (0,0,imgwidth/2,imgheight)
        left = img.crop(leftbox)
        last_saved_page += 1
        create_thumbs_and_save(left,imgwidth/2,imgheight,last_saved_page,file)

        rightbox = (imgwidth/2,0,imgwidth,imgheight)
        right = img.crop(rightbox)
        last_saved_page += 1
        create_thumbs_and_save(right,imgwidth/2,imgheight,last_saved_page,file)
        pass
    else:
        last_saved_page += 1
        create_thumbs_and_save(img,imgwidth,imgheight,last_saved_page,file)

for file in files:
    split(file)