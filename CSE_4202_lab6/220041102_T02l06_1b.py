import cv2

def blur_image(input_image_path, output_image_path):
    # Read the input image
    image = cv2.imread(input_image_path)

    # Check if the image was read successfully
    if image is None:
        print("Error: Unable to read input image.")
        return

    # Apply blur effect
    blurred_image = cv2.blur(image, (5, 5))  # You can adjust the kernel size for different blur effects

    # Save the blurred image
    cv2.imwrite(output_image_path, blurred_image)

    print("Image blurred and saved successfully.")

# Example usage
input_image_path = "d:/IUT accademic/CSE_4202_lab6/100dollars.tif"
output_image_path = "d:/IUT accademic/CSE_4202_lab6/blurred_image_python.tif"
blur_image(input_image_path, output_image_path)
