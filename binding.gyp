{
  "targets": [{
    "target_name": "native-add",
    "sources": ["src/add.cc"],
    "include_dirs": [
      "src",
      "<!(node -e \"require('nan')\")"
    ]
  }]
}
