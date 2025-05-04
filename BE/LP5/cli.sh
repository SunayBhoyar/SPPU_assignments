#!/bin/bash

REPO_OWNER="SunayBhoyar"
REPO_NAME="SPPU_assignments"
GITHUB_API="https://api.github.com"
RAW_CONTENT_URL="https://raw.githubusercontent.com"

echo "Enter the subject HPC / DL :"
read subject

case "$subject" in
"HPC" | "DL") ;;
*)
    echo "Invalid subject name. Please choose from HPC or DL."
    exit 1
    ;;
esac

# List available folders (like 1, 2, 3, 4)
folders_json=$(wget -qO- "${GITHUB_API}/repos/${REPO_OWNER}/${REPO_NAME}/contents/BE/LP5/${subject}")

echo "Available folders in $subject:"
folder_list=$(echo "$folders_json" | grep '"name":' | sed -n 's/.*"name": "\([^"]*\)".*/\1/p')
counter=1
while IFS= read -r folder; do
    echo "$counter) $folder"
    counter=$((counter + 1))
done <<<"$folder_list"

echo "Enter the number of the folder you want to download:"
read folder_number

selected_folder=$(echo "$folder_list" | sed -n "${folder_number}p")

if [ -z "$selected_folder" ]; then
    echo "Invalid selection."
    exit 1
fi

# Get list of files in the selected folder
files_json=$(wget -qO- "${GITHUB_API}/repos/${REPO_OWNER}/${REPO_NAME}/contents/BE/LP5/${subject}/${selected_folder}")

# Make directory for the folder
mkdir -p "${selected_folder}"

# Loop through and download each file
echo "Downloading files from folder '$selected_folder'..."
for file_url in $(echo "$files_json" | grep '"download_url":' | sed -n 's/.*"download_url": "\(.*\)",/\1/p'); do
    filename=$(basename "$file_url")
    wget -q "$file_url" -O "${selected_folder}/${filename}"
    echo "Downloaded: $filename"
done

echo "All files from '$selected_folder' have been downloaded into the ./${selected_folder} folder."
