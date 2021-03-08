{
  "targets": [{
    "target_name": "resetv8timezone",
    "include_dirs": [ "<!(node -e \"require('nan')\")" ],
    "sources": [ "src/binding.cc" ]
  }]
}
