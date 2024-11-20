import { Place as PlaceIcon, Delete as DeleteIcon } from '@mui/icons-material';
import { IconButton, ListItem, ListItemIcon, ListItemText } from '@mui/material';

export default function FeatureListItem({feature, onDelete}) {
    const name = feature.get('name');

    const deleteButton =
        <IconButton onClick={onDelete} aria-label="изтрий">
            <DeleteIcon />
        </IconButton>;

    return (
        <ListItem secondaryAction={deleteButton}>
            <ListItemIcon>
                <PlaceIcon />
            </ListItemIcon>
            <ListItemText
                primary={name ? name : '[Обект на картата]'}
                primaryTypographyProps={name ? {} : {sx: {fontStyle: 'italic'}}}
            />
        </ListItem>
    );
}
