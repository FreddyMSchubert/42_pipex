#!/bin/bash

# Script: execute_pipex_and_check

# File paths
input_file="../infile"
output_file="../outfile"
temp_file="temp_output.txt"

# Check if infile and outfile exist, create them if not
[ -f "$input_file" ] || touch "$input_file"
[ -f "$output_file" ] || touch "$output_file"

# generated using https://www.randomtextgenerator.com/
echo "Its sometimes her behaviour are contented. Do listening am eagerness oh objection collected. Together gay feelings continue juvenile had off one. Unknown may service subject her letters one bed. Child years noise ye in forty. Loud in this in both hold. My entrance me is disposal bachelor remember relation.
Effects present letters inquiry no an removed or friends. Desire behind latter me though in. Supposing shameless am he engrossed up additions. My possible peculiar together to. Desire so better am cannot he up before points. Remember mistaken opinions it pleasure of debating. Court front maids forty if aware their at. Chicken use are pressed removed.
Certainty determine at of arranging perceived situation or. Or wholly pretty county in oppose. Favour met itself wanted settle put garret twenty. In astonished apartments resolution so an it. Unsatiable on by contrasted to reasonable companions an. On otherwise no admitting to suspicion furniture it.
Looking started he up perhaps against. How remainder all additions get elsewhere resources. One missed shy wishes supply design answer formed. Prevent on present hastily passage an subject in be. Be happiness arranging so newspaper defective affection ye. Families blessing he in to no daughter.
Those an equal point no years do. Depend warmth fat but her but played. Shy and subjects wondered trifling pleasant. Prudent cordial comfort do no on colonel as assured chicken. Smart mrs day which begin. Snug do sold mr it if such. Terminated uncommonly at at estimating. Man behaviour met moonlight extremity acuteness direction.
Am finished rejoiced drawings so he elegance. Set lose dear upon had two its what seen. Held she sir how know what such whom. Esteem put uneasy set piqued son depend her others. Two dear held mrs feet view her old fine. Bore can led than how has rank. Discovery any extensive has commanded direction. Short at front which blind as. Ye as procuring unwilling principle by.
Surrounded affronting favourable no mr. Lain knew like half she yet joy. Be than dull as seen very shot. Attachment ye so am travelling estimating projecting is. Off fat address attacks his besides. Suitable settling mr attended no doubtful feelings. Any over for say bore such sold five but hung.
He oppose at thrown desire of no. Announcing impression unaffected day his are unreserved indulgence. Him hard find read are you sang. Parlors visited noisier how explain pleased his see suppose. Do ashamed assured on related offence at equally totally. Use mile her whom they its. Kept hold an want as he bred of. Was dashwood landlord cheerful husbands two. Estate why theirs indeed him polite old settle though she. In as at regard easily narrow roused adieus.
Full he none no side. Uncommonly surrounded considered for him are its. It we is read good soon. My to considered delightful invitation announcing of no decisively boisterous. Did add dashwoods deficient man concluded additions resources. Or landlord packages overcame distance smallest in recurred. Wrong maids or be asked no on enjoy. Household few sometimes out attending described. Lain just fact four of am meet high.
Advantage old had otherwise sincerity dependent additions. It in adapted natural hastily is justice. Six draw you him full not mean evil. Prepare garrets it expense windows shewing do an. She projection advantages resolution son indulgence. Part sure on no long life am at ever. In songs above he as drawn to. Gay was outlived peculiar rendered led six.
" > "$input_file"

# Clear the output file
> "$output_file"

make fcomp

# Construct the shell pipeline command
shell_command="< $input_file "
for cmd in "$@"; do
    shell_command+="$cmd | "
done
shell_command+=" cat"

# Execute the shell pipeline command and save the output
eval $shell_command > $temp_file

# Construct and execute the pipex command
pipex_command="../pipex $input_file "
for cmd in "$@"; do
    pipex_command+='"'$cmd'" '
done
pipex_command+="$output_file"

# Execute the pipex command
eval $pipex_command

# Compare outputs
if cmp -s "$temp_file" "$output_file"; then
    echo "✅ Outputs match"
else
    echo "❌ Outputs do not match"
fi

# Clean up
rm -f $temp_file
