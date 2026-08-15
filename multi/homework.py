import numpy as np
import matplotlib.pyplot as plt
from skimage import color, exposure, io
from PIL import Image, ImageDraw, ImageFont

# 1. Load your color image
# (skimage loads images into standard RGB NumPy arrays)
img = io.imread("colorful.jpeg")

# 2. Convert from RGB to HSV color space
# Output arrays will be floating-point numbers from 0.0 to 1.0
hsv_img = color.rgb2hsv(img)

# 3. Try CLAHE with 3 different kernel_size values and compare them side by side
kernel_sizes = [32, 64, 128]
fig, axes = plt.subplots(1, len(kernel_sizes), figsize=(15, 5))
for ax, k in zip(axes, kernel_sizes):
    hsv_trial = hsv_img.copy()
    hsv_trial[:, :, 2] = exposure.equalize_adapthist(hsv_trial[:, :, 2], kernel_size=k)
    rgb_trial = color.hsv2rgb(hsv_trial)
    ax.imshow(rgb_trial)
    ax.set_title(f"kernel_size = {k}")
    ax.axis("off")
plt.show()

# 4. Pick the kernel_size that looked best in the comparison above
kernel_size = 64  # <- chosen after comparing 32 / 64 / 128
hsv_img[:, :, 2] = exposure.equalize_adapthist(hsv_img[:, :, 2], kernel_size)

# 5. Convert back from HSV to standard RGB
output_rgb = color.hsv2rgb(hsv_img)

# 6. Display the final chosen result
plt.imshow(output_rgb)
plt.axis("off")
plt.show()

# 1. If your image is stored using skimage, you need to convert to PIL Image first
# output_rgb is a skimage float array (0.0-1.0), so scale to 0-255 uint8 first
pil_img = Image.fromarray((output_rgb * 255).astype(np.uint8))
# 2. Create an ImageDraw object
draw = ImageDraw.Draw(pil_img) #img must be PIL Image object
#set the content to add. Make change to the sample below
text_content = f"Name: Puttipong Pruthisathaporn, Student ID:68070129, kernel size= {kernel_size}"
text_color = (255, 255, 255) # Change to your color
# 4. Draw the text (using a custom font with a bigger size)
custom_font = ImageFont.truetype("/System/Library/Fonts/Supplemental/Arial.ttf", size=30)
# 3. Choose coordinates (X/Column, Y/Row) - keep it near the bottom of the image
text_bbox = draw.textbbox((0, 0), text_content, font=custom_font)
text_height = text_bbox[3] - text_bbox[1]
bottom_margin = 40
text_position = (550, pil_img.height - text_height - bottom_margin)
draw.text(text_position, text_content, fill=text_color, font=custom_font)
# 5. Save or show the result
pil_img.show()
pil_img.save(f"68070129_kernel_{kernel_size}.jpg")
