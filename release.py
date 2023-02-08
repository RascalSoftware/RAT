"""This uploads a build artifact with the given filename as an assets in the GitHub 
nightly release. If the asset already exists on GitHub, the existing one will be 
deleted and replaced with the new build 

USAGE: 

    python release.py GITHUB_TOKEN FILENAME
"""
import argparse
import json
import urllib.request

TOKEN = ''
HEADERS = {}
RELEASE_ID = 91574157  # ID of the nightly release

def deleteAsset(assetID):
    """Deletes a given asset from a GitHub release

    :param assetID: ID of the asset to remove
    :type assetID: int
    """
    url = f'https://api.github.com/repos/RascalSoftware/RAT/releases/assets/{assetID}'
    request = urllib.request.Request(url, headers=HEADERS, method='DELETE')
    urllib.request.urlopen(request)


def uploadAsset(filename):
    """Uploads a file as a GitHub release asset

    :param filename: name of file to upload
    :type filename: string
    """
    with open(filename, 'rb') as fp:
        data = fp.read()

    url = f'https://uploads.github.com/repos/RascalSoftware/RAT/releases/{RELEASE_ID}/assets?name={filename}"'
    headers = {**HEADERS, 'Content-Type': 'application/octet-stream'}
    request = urllib.request.Request(url, headers=headers, method='POST', data=data)
    urllib.request.urlopen(request)
    

def getAssets():
    """Gets all the assets for a specific release
    
    :return: asset name and id pair
    :rtype: filename: Dict[string, int]
    """
    url = f'https://api.github.com/repos/RascalSoftware/RAT/releases/{RELEASE_ID}/assets'
    request = urllib.request.Request(url, headers=HEADERS)
    with urllib.request.urlopen(request) as response:
        assets = json.loads(response.read())
        return {asset.get('name'): asset.get('id') for asset in assets}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Helper to upload build to GitHub.')
    parser.add_argument('token', help='Github token')
    parser.add_argument('filename', help='name of file to upload')

    args = parser.parse_args()
    TOKEN = args.token
    HEADERS = {'Accept': 'application/vnd.github+json', 'Authorization': f'Bearer {TOKEN}', 
               'X-GitHub-Api-Version': '2022-11-28'}

    assets = getAssets()
    if args.filename in assets:
        deleteAsset(assets[args.filename])
    uploadAsset(args.filename)
    print(f'{args.filename} uploaded successfully!')
