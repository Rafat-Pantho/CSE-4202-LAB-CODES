from PIL import Image

def flip_horizontal(image_path, save_path):
    # Open the image
    image = Image.open(image_path)
    
    # Flip the image horizontally
    flipped_image = image.transpose(Image.FLIP_LEFT_RIGHT)
    
    # Save the flipped image
    flipped_image.save(save_path)

# Example usage
input_image_path = "d:/IUT accademic/CSE_4202_lab6/100dollars.tif"
output_image_path = "d:/IUT accademic/CSE_4202_lab6/flipped_image_python.tif"
flip_horizontal(input_image_path, output_image_path)
